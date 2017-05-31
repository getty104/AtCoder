require 'prime'
require 'set'
require 'tsort'
include Math
def max(a,b);              a > b ? a : b                              end
def min(a,b);              a < b ?  a : b                             end
def swap(a,b);             a, b = b, a                                end
def gif;                   gets.to_i                                  end
def gff;                   gets.to_f                                  end
def gsf;                   gets.chomp                                 end
def gi;                    gets.split.map(&:to_i)                     end
def gf;                    gets.split.map(&:to_f)                     end
def gs;                    gets.chomp.split.map(&:to_s)               end
def gc;                    gets.chomp.split('')                       end
def pr(num);               num.prime_division                         end
def digit(num);            num.to_s.length                            end
def array(s,ini=nil);      Array.new(s){ini}                          end
def darray(s1,s2,ini=nil); Array.new(s1){Array.new(s2){ini}}          end
def rep(num);              num.times{|i|yield(i)}                     end
def repl(st,en,n=1);       st.step(en,n){|i|yield(i)}                 end

n = gif
a = gi
if n % 2 != 0
  aa = a.dup
  ab = a.dup
  num = 0
  rep n do |i|
    num = i if a[num] > a[i]
  end
  num = 0
  aa.delete_at(num)
  rep n do |i|
    num = i if a[num] < a[i]
  end
  ab.delete_at(num)

  a1 = aa.slice(0,a.size/2)
  a2 = aa.slice(a.size/2,a.size-1)
  a1.sort!
  a2.sort!
  loop{
    break if a1.size == n
    a1.shift
    a2.pop
  }
  ans1 = a1.inject(:+)-a2.inject(:+)
  a1 = ab.slice(0,a.size/2)
  a2 = ab.slice(a.size/2,a.size-1)
  a1.sort!
  a2.sort!
  loop{
    break if a1.size == n
    a1.shift
    a2.pop
  }
  ans2 = a1.inject(:+)-a2.inject(:+)
  puts max ans1,ans2
else
  a1 = a.slice(0,a.size/2)
  a2 = a.slice(a.size/2,a.size-1)
  a1.sort!
  a2.sort!
  loop{
    break if a1.size == n
    a1.shift
    a2.pop
  }

  puts a1.inject(:+)-a2.inject(:+)

end


