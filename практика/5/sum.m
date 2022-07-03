function res=sum(x)
  res = 0;
  [n, m] = size(x);
  for i=1:n
    for j=1:m
      if j <= i && x(i, j) < 0
        res += x(i, j);
      endif
    endfor
  endfor
  res;

