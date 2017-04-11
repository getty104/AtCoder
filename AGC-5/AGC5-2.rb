
N = gets.to_i
a = gets.split.map(&:to_i)
a.sort!
ans = 0
amo = 0
N.times do |i|
	amo += a[i]
	ans += amo 
end

puts ans