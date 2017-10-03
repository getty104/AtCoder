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

n,m = gi
d = []
rep m do
 d << gi
end
d.sort_by!{|a,b,c| c }

q = gif
u = UnionFindTree.new
ans = []
user = []
rep q do |i|
  user << [i]+gi
end

user.sort_by!{|a,b,c| c }.reverse!
user.each do |uu|
  loop{
    if d.empty? || uu[2]>=d[-1][2]
      ans << [uu[0],u.size(uu[1])]
      break
    else
     tmp = d.pop
     u.unite tmp[0],tmp[1]
   end
 }
end

ans.sort_by{|a,b| a }.each do |a|
puts a[1]
end