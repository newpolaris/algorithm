ARGV << "baseball.txt"

gets.to_i.times do
  team = Hash.new
  list = Array.new
  8.times do |i|
    str = gets
    str, w, d, l = str.chop.split
    team[str] = i
    list << [w.to_i, d.to_i, l.to_i]
  end
  my = team[gets.chop]
  gets.to_i.times do
    t1, t2 = gets.chomp.split
    n1 = team[t1]
    n2 = team[t2]

    if n1 != my && n2 != my
      list[n1][1] += 1
      list[n2][1] += 1
    else
      if n1 == my
        list[n1][0] += 1
        list[n2][2] += 1
      else
        list[n1][2] += 1
        list[n2][0] += 1
      end
    end
  end
  result = Array.new
  list.each { |w, d, l| result << w.to_f / (w+d+l) }
  myown = result[my]
  rank = 0
  result.each { |score| rank += 1 if score > myown }
  if rank < 4
    puts 'YES'
  else
    puts 'NO'
  end
end
