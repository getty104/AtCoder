require 'prime'
include Math
def max(a,b);                           a > b ? a : b                             end
def min(a,b);                           a < b ?  a : b                            end
def swap(a,b);                          a, b = b, a                               end
def gif;                                gets.to_i                                 end
def gi;                                 gets.split.map(&:to_i)                    end
def gs;                                 gets.chomp                                end
def gc;                                 gets.chomp.split('')                      end
def pr(num);                            num.prime_division                        end
def putall(obj);                        obj.each{|o| puts(o)}                     end
def array(size,init = nil);             Array.new(size){init}                     end
def darray(size1, size2, init = nil);   Array.new(size1){Array.new(size2){init}}  end
def rep(num);                           num.times do|i|yield(i) end               end
  def repl(st,en);                      st.upto en-1 do|i|yield(i) end            end

  def culcx x
  	if x > 0
  		"R" * x
  	elsif x < 0
  		"L" * -x
  	end
  end

  def culcy y
  	if y > 0
  		"U" * y
  	elsif y < 0
  		"D" * -y
  	end
  end

  sx,sy,tx,ty = gi
  str = ""
 	x = tx-sx
 	y = ty-sx
 	if x > 0 && y >0
 	str += culcy y
 	str += culcx x
 	str += culcy -y
 	str += culcx -x
 	str += culcx -1
 	str += culcy y+1
 	str += culcx x+1
 	str += culcy -1
 	str += culcx 1
 	str += culcy -(y+1)
 	str += culcx -(x+1)
 	str += culcy 1
 	puts str
 elsif x > 0 && y < 0
 elsif x < 0 && y < 0
 elsif x < 0 && y > 0
 end
