#! /usr/bin/env ruby
require 'mechanize'
require 'set'

# 参考 http://www.lijiejie.com/post/vb6-domain-hunter.html
# 获取域名的所有子域名
# E.g. subdomain.rb youku.com
# version 1: single process, single thread
#
domain_name = ARGV[0]
unless domain_name
  puts 'usage: xx.rb domain_name'
  exit 1
end

agent = Mechanize.new do |agent|
  agent.user_agent_alias = 'Mac Safari'
end

# 获取signature, 设置返回结果数
base_uri = 'https://www.google.com'
sig = ''
agent.get("#{base_uri}/preferences?hl=zh-CN") do |page|
  sig = page.forms.first['sig']
end
agent.get("#{base_uri}/setprefs?sig=#{sig}&hl=zh-CN&lr=lang_zh-CN&suggon=2&num=100&newwindow=1&c2coff=true")

# 翻页查询，直到结束
# 去除重复项
start_time = Time.now
subdomains = SortedSet.new
search_uri = "#{base_uri}/search?num=100&hl=zh-CN&newwindow=1&source=hp&q=site:#{domain_name}"
while search_uri
  agent.get(search_uri) do |page|
    page.search('cite').each do |e|
      # 提取子域名
      subdomains.add(e.content.gsub(/[\/\s].*/, ''))
    end

    search_uri = nil
    page.search('#nav .navend #pnnext').each do |e|
      search_uri = e.attributes['href']
    end
  end
end
end_time = Time.now

subdomains.each { |v| puts v }
puts "total: #{subdomains.size}"

pid, size = `ps ax -o pid,rss | grep -E "^[[:space:]]*#{Process::pid}"`.chomp.split(/\s+/).map { |s| s.strip.to_i }
puts %Q{used time: #{end_time - start_time}s, used memory: #{size / 1024}kb}

