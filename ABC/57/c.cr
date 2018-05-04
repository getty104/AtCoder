n = gets.not_nil!.to_i64
tmp1 = n
tmp2 = 1_i64
limit = n/10
1.upto(limit) do |prime|
  if n % prime == 0
    tmp1 = n/prime
    tmp2 = prime
    break if tmp1 <= tmp2
  end
end
tmp2 = n if tmp2 == 1
puts Math.log10(tmp2).to_i + 1
