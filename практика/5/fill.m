function [res, sm]=fill(a, b, c, d ,e)
  sm = 0;
  res = zeros(a, b);
  arr = [c, d, e];
  [n, ind] = min(arr);
  arr(ind) = [];
  m = min(arr);
  k1 = 0;
  k2 = 0;
  if (n <= a && m <= b)
    k1 = idivide(a, int32(n), "fix");
    k2 = idivide(b, int32(m), "fix");
    sm += k1*k2;
    res(1:n*k1, 1:m*k2) = 1;
  endif
  restB = b - m*k2;
  if (m <= a && n <= b)
    begin = m*k2+1;
    k1 = idivide(restB, int32(n), "fix");
    k2 = idivide(a, int32(m), "fix");
    sm += k1*k2;
    res(1:m*k2, begin:begin+n*k1-1) = 1;
  endif
  res
  sm


