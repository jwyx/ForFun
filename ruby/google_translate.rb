#! /usr/bin/env ruby
require 'mechanize'

# Credit: http://xiaoxins.com/archives/503#more-503
# ruby版google translator

agent = Mechanize.new do |agent|
  agent.user_agent_alias = 'Mac Safari'
end

if ARGV.size < 1 # usage
  puts %q{usage:
          xx.rb text [target_lang [source_lang]]
          xx.rb -lang
  }
  exit 1
elsif ARGV.size == 1 && ARGV[0] == '-lang' # list all lang
  base_uri = "https://developers.google.com"
  agent.get("#{base_uri}/translate/v2/using_rest#language-params") do |page|
    page.search('#gc-content').each do |container|
      container.search('#language-params + p').each do |p|
        puts p.content
      end

      container.search('table').each do |table|
        if /\A\s*language\s*\z/i =~ table.search('thead tr th').first
          puts table.search('tbody tr td code').map { |e| e.content }.join(", ")
        end
      end
    end
  end
else # translate
  raw_text, t_lang, s_lang = ARGV
  t_lang ||= 'zh-CN'
  s_lang ||= 'auto'

  text = raw_text.strip
  base_uri = "http://translate.google.com"
  agent.get("#{base_uri}?sl=#{s_lang}&tl=#{t_lang}&text=#{text}") do |page|
    print "s: #{text}\nt: "
    page.search('#result_box span').each { |e| puts e.content }
  end
end

