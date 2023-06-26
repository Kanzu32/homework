function print()
  x = -1:0.05:1;
  y = f1(x);
  figure
  plot(x, y);
  figure
  fplot('f1', [-1, 1]);
