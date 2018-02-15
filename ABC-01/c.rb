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

deg,dis = gi

dr = case (dis.to_f/6).round
when 0..2 then 0
when 3..15 then 1
when 16..33 then 2
when 34..54 then 3
when 55..79 then 4
when 80..107 then 5
when 108..138 then 6
when 139..171 then 7
when 172..207 then 8
when 208..244 then 9
when 245..284 then 10
when 285..326 then 11
else 12
end

dg  = dr == 0 ? 'C' : case deg * 10
when 1125...3375 then 'NNE'
when 3375...5625 then 'NE'
when 5625...7875 then 'ENE'
when 7875...10125 then 'E'
when 10125...12375 then 'ESE'
when 12375...14625 then 'SE'
when 14625...16875 then 'SSE'
when 16875...19125 then 'S'
when 19125...21375 then 'SSW'
when 21375...23625 then 'SW'
when 23625...25875 then 'WSW'
when 25875...28125 then 'W'
when 28125...30375 then 'WNW'
when 30375...32625 then 'NW'
when 32625...34875 then 'NNW'
else 'N'
end

puts "#{dg} #{dr}"
