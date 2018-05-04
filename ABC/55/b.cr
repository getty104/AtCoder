n = gets.not_nil!.to_u64
ans = 1_u64
n.times do |i|
  ans *= (i + 1)
  ans %= (10**9 + 7)
end

puts ans
