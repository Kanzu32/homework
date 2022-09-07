function res=textFunc(str)
  ind = strfind(str, ' ');
  ind(length(ind)+1) = length(str)+1;
  last = 1;
  for i=1:length(ind)
    if rem(ind(i) - last, 2) ~= 0
      delInd = last + idivide((ind(i) - last), int32(2), 'floor');
      if (exist('res') == 0)
        res = [str(last:delInd-1), str(delInd+1:ind(i)-1)];
      else
        res = [res, ' ', str(last:delInd-1), str(delInd+1:ind(i)-1)];
      endif
    else
      if (exist('res') == 0)
        res = str(last:ind(i)-1);
      else
        res = [res, ' ', str(last:ind(i)-1)];
      endif
    endif
    last = ind(i)+1;

  endfor

