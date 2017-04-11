
N,A,B = gets.split.map(&:to_i)
count = 0
N.times do
	t = gets.to_i
	if t<A||B<=t
		count+=1
	end
end

puts count