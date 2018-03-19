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

n = gif

a = []
c = []
rep n do
  a << gi
end

rep n do
  c << gi
end

a1 = a.sort
c1 = c.sort
a2 = a.sort_by{|ta|ta[1]}
c2 = c.sort_by{|ta|ta[1]}

ct1 = 0
a1.each do |ta|
  rep c1.size do |i|
    if ta[0] < c1[i][0] && ta[1] < c1[i][1]
      ct1+=1
      c1.delete_at(i)
      break
    end
  end
end

ct2 = 0
a2.each do |ta|
  rep c2.size do |i|
    if ta[0] < c2[i][0] && ta[1] < c2[i][1]
      ct2+=1
      c2.delete_at(i)
      break
    end
  end
end

puts max ct1,ct2
