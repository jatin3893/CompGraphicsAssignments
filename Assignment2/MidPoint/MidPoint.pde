int MaxHeight = 700;
int MaxWidth = 700;

int X1 = 0, Y1 = 0, X2 = 14, Y2 = 2;
int dx = X2 - X1;
int dy = Y2 - Y1;
int d = 2 * dy - dx;
int incrE = 2 * dy;
int incrNE = 2 * (dy - dx);
int x = X1;
int y = Y1;
int Scale = 40;

void setup()
{
  size(MaxHeight, MaxWidth);
  background(255, 255, 255);
  stroke(0);
  strokeWeight(5);
  int i;
  for (i = 0; i < MaxHeight; i += Scale)
    line(0, i, MaxWidth, i);
  
  for (i = 0; i < MaxWidth; i += Scale)
    line(i, 0, i, MaxHeight);

  strokeWeight(1);
  for (i = 0; i < MaxHeight; i += Scale / 2)
    line(0, i, MaxWidth, i);
    
  for (i = 0; i < MaxWidth; i += Scale / 2)
    line(i, 0, i, MaxHeight);
}

void draw()
{  
  stroke(0, 255, 0);
  line(X1 * Scale, Y1 * Scale, X2 * Scale, Y2 * Scale);
  fill(0, 0, 0);
  fill(255, 0, 0, 100);
}
void keyPressed()
{
  if (key == '\n')
  {    
    if (x < X2)
    {
      String DString = "Delta = " + d;
      if (d <= 0)
      {
        d += incrE;
      } else
      {
        d += incrNE;
        y++;
      }
      x++;
      int GraphX = x * Scale;
      int GraphY = y * Scale;
      String GraphXString = "X = " + x;
      String GraphYString = "Y = " + y;

      ellipse(GraphX, GraphY, Scale, Scale);
      stroke(255, 255, 255);
      fill(0, 0, 0);
      rect(0, 350, 200, 200);
      fill(255, 255, 255);
      textSize(30);
      text(DString, 0, 410);
      text(GraphXString, 0, 440);
      text(GraphYString, 0, 470);
    }
  }
}
