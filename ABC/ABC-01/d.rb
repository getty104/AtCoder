require 'prime'
require 'set'
require 'tsort'
include Math
ALP = ('a'..'z').to_a
INF = 0xffffffffffffffff
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
def pr?(num);              Prime.prime?(num)                          end
def digit(num);            num.to_s.length                            end
def array(s,ini=nil);      Array.new(s){ini}                          end
def darray(s1,s2,ini=nil); Array.new(s1){Array.new(s2){ini}}          end
def rep(num);              num.times{|i|yield(i)}                     end
def repl(st,en,n=1);       st.step(en,n){|i|yield(i)}                 end

n=gif
s =  301
t = array s,0
rep n do
  d1,d2 = gsf.split('-').map(&:to_i)
  t[(d1/100)*12+(d1%100)/5] += 1
  t[(d2/100)*12+(d2%100>0?(d2%100-1)/5+1:0)] -= 1
end

repl 1, s-1 do |i|
  t[i] += t[i-1]
end

ans = []
flag = false
st = nil
rep s do |i|
  if t[i] > 0 && !flag
    st = i
    flag = true
  elsif t[i] == 0 && flag
    ans << "#{"%#04d" %  ((st/12)*100+(st%12)*5)}-#{"%#04d" %  ((i/12)*100+(i%12)*5)}"
    flag = false
  end
end

puts ans
