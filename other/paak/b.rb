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
m = []
rep n do
  m << gi
end
i,j = gi
i -= 1
j -= 1
ti, tj = i,j
loop{
  tmpm = m[ti][tj]
  tti = ti
  ttj = tj
  if tj < n-1
    if tmpm >= m[ti][tj+1]
      tmpm = m[ti][tj+1]
      ttj = tj+1
      tti = ti
    end
  end

  if ti < n-1
    if tmpm >= m[ti+1][tj]
      tmpm = m[ti+1][tj]
      tti = ti+1
      ttj = tj
    end
  end

  if tj > 0
    if tmpm >= m[ti][tj-1]
      tmpm = m[ti][tj-1]
      ttj = tj-1
      tti = ti
    end
  end


  if ti > 0
    if tmpm >= m[ti-1][tj]
      tmpm = m[ti-1][tj]
      tti = ti-1
      ttj = tj
    end
  end


  if tmpm >= m[ti][tj]
    break
  else
    ti = tti
    tj = ttj
  end
}

puts "#{ti+1} #{tj+1}"
