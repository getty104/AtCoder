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

class UnionFindTree

  class ParArray < Hash
    def [] key
      self[key] = key if super(key).nil?
      super(key)
    end
  end

  class SizeArray < Hash
    def [] key
      self[key] = 1 if super(key).nil?
      super(key)
    end
  end

  def initialize()
    @par = ParArray.new
    @size = SizeArray.new
  end

  private

  def find(x)
    return x if x == @par[x]
    return @par[x] = find(@par[x])
  end

  public

  def unite(x, y)
    x = find(x)
    y = find(y)

    return nil if x == y
    x, y = y, x if @size[x] < @size[y]

    @par[y] = x
    @size[x] += @size[y]
  end

  def same?(x, y)
    return find(x) == find(y)
  end

  def size(x)
    return @size[find(x)]
  end

end




br = UnionFindTree.new
wh = UnionFindTree.new
q1 = []
q2 = []
n = gif

m = array n+1,[]
rep n-1 do
  a,b = gi
  m[a] << b
  m[b] << a
end
bb = 1
ww = n
q1 << bb
q2 << ww
loop{
  loop{
    bb = q1.shift
    if wh.same?(n,bb)
      bb = q1.shift
      next
    else
      br.unite(1,bb)
      m[bb].each do |bbb|
        q1 << bbb
      end
      break
    end
  }

 loop{
    ww = q2.shift
    if br.same?(1,ww)
      ww = q2.shift
      if ww.nil?
      end
      next
    else
      wh.unite(n,ww)
      m[ww].each do |www|
        q1 << www
      end
      break
    end
  }
}

puts br.size(1) > wh.size(n) ? 'Fennec' : 'Snuke'
