from math import *
from sympy import *
x, y, x0, y0 = symbols("x y x0 y0")
f = 1/(2*pi) * (log(sqrt( (x - x0)**2 + (y + y0)**2 )/sqrt( (x - x0)**2 + (y - y0)**2 ) ) - log(sqrt( (x + x0)**2 + (y + y0)**2 )/sqrt( (x + x0)**2 + (y - y0)**2 ) ))
print("a", f.subs(y,0))
dx = diff(f,'x')
print("b", dx.subs(x,0))
dy = diff(f, 'y')
print("c", dy.subs(x,0))
print("d", f.subs(x,0))