void initialiseGrid()
{
    print("In");

  stroke(0);
  strokeWeight(1);
  for (int i = 0; i < MaxWidth; i += Scale)
    line(i, 0, i, MaxHeight);
  for (int i = 0; i < MaxHeight; i += Scale)
    line(0, i, MaxWidth, i);

  strokeWeight(2);
  for (int i = Scale / 2; i < MaxWidth; i += Scale)
    line(i, 0, i, MaxHeight);
  for (int i = Scale / 2; i < MaxHeight; i += Scale)
    line(0, i, MaxWidth, i);
}

  void ColorCell(int x, int y, int red, int green, int blue)
{
  fill(red, green, blue);
  ellipse(x * Scale, y * Scale, Scale, Scale);
}

void setup()
{
  size(MaxWidth, MaxHeight);
  background(255);
  initialiseGrid();
}

void draw()
{
  keyPressed();
}
