#! /usr/bin/env ruby

# From book programming ruby 1.9

if ARGV.size < 1
  puts 'usage: xx.rb input_file'
  exit 1
end

data_file = ARGV[0]

words = Fiber.new do
  File.foreach(data_file) do |line|
    line.scan(/\w+/) do |word|
      Fiber.yield word.downcase
    end
  end
end

counts = Hash.new(0)
while word = words.resume
  counts[word] += 1
end

counts.keys.sort.each do |k|
  puts "#{k} #{counts[k]}"
end
