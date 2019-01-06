a,b,c=map(int,sorted([input(),input(),input()]))
print('Error'if a+b+c!=180 else'Equilateral'if a==c else'Isosceles'if a==b or b==c else'Scalene')
