
N , K = gets.split.map(&:to_i)

list = Hash.new
('A'..'Z').each do |key|
	list[key] = Array.new
end
N.times do
	str = gets.to_s
	list[str[0]].push(str)
end
ans = 0
count = 0
jd = false
loop{
	('A'..'Z').each do |key|
		if !list[key].empty?
			list[key].pop
			count+=1
			if count == K 
				count=0
				ans+=1
				jd = true
				break
			end
		end
	end
	if jd == false
		break
	else
		jd = false
	end

}

puts ans
