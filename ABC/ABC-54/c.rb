def f v, list, num, n
	ans = 0
	jd = true
	list.each do |ll|
		if ll == 0
			jd = false 
			break
		end
	end
	if jd 
		return 1 
	end
	n.times do |i|
		next if i == num 
		next if list[i] == 1
		if v[num][i] == 1 
			list[i] = 1 
			ans +=	f v,list, i, n
			list[i] = 0
		end
	end
	return ans
end


N,M = gets.split.map(&:to_i)

v = Array.new(N){Array.new(N){0}}

M.times do
	a = gets.split.map(&:to_i)
	v[a[0] - 1][a[1] - 1] = 1
	v[a[1] - 1][a[0] - 1] = 1
end
list = Array.new(N){0}
list[0] = 1

ans = f v, list, 0, N

puts ans