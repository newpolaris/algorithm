gets.to_i.times {
  str = gets.chop
  (0...str.length).each { |i|
    if i % 2 == 0
      putc str[i]
    end
  }

  (0...str.length).each { |i|
    putc str[i] if i % 2 == 1
  }
  print "\n"
}