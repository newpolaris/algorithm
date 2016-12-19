fibo = Hash.new {|h,k| h[k] = h[k-1] + h[k-2]}
fibo[0] = 1
fibo[1] = 1
gets.to_i.times {p fibo[gets.to_i] % (10**9+7)}
