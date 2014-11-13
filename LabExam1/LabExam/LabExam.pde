/*
Jatin Parekh
2011A7PS006G
Lab Exam 1 Submission
14th October, 2014
*/
Point[] coloured = new Point[10000];// max 10000 elements in the array
boolean[][] colouredMap = new boolean[100][100];
int Count = 0;

int ToBeColoured = -1;
int DeltaX = 20;

int MaxHeight = 700;
int MaxWidth = 700;
int Scale = 26;
boolean RectangleSelected = false;
boolean PointSelected = false;
int clickCount = 0;
int x1, y1, x2, y2, lastX, lastY;
int k = 0;

void setup()
{
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
      colouredMap[i][j] = false;

  size(MaxHeight, MaxWidth);
  background(255);
  drawGrid();
  DisplayArray();
}

void drawGrid()
{
  int i;
  stroke(0);
  for (i = 0; i < MaxHeight; i += Scale)
    line(0, i, MaxWidth, i);

  for (i = 0; i < MaxWidth; i += Scale)
    line(i, 0, i, MaxHeight);
}

void FillCell(int X, int Y, int red, int green, int blue)
{
  fill(red, green, blue);
  rect(X * Scale, Y * Scale, Scale, Scale);
}

void draw()
{
}

void mouseClicked()
{
  if (!RectangleSelected)
  {
    clickCount++;
    if (clickCount == 1)
    {
      lastX = mouseX / Scale;
      lastY = mouseY / Scale;
    } else {
      clickCount = 0;
      if (mouseY / Scale < lastY)
      {
        x1 = mouseX / Scale;
        y1 = mouseY / Scale;
        x2 = lastX + 1;
        y2 = lastY + 1;
      } else
      {
        x2 = mouseX / Scale + 1;
        y2 = mouseY / Scale + 1;
        x1 = lastX;
        y1 = lastY;
      }
      strokeWeight(4);
      line(x1 * Scale, y1 * Scale, x1 * Scale, y2 * Scale);
      line(x1 * Scale, y1 * Scale, x2 * Scale, y1 * Scale);
      line(x2 * Scale, y2 * Scale, x1 * Scale, y2 * Scale);
      line(x2 * Scale, y2 * Scale, x2 * Scale, y1 * Scale);
      strokeWeight(0);
      RectangleSelected = true;
    }
    return;
  }
  if (!PointSelected)
  {
    if (InRect(mouseX / Scale, mouseY / Scale))
    {
      coloured[Count++] = new Point(mouseX / Scale, mouseY / Scale);
      colouredMap[mouseX / Scale][mouseY / Scale] = true;
      ToBeColoured = 0;
      PointSelected = true;
      NextIter();
      DisplayArray();
    } else
    {
      fill(0);
      text("Outside Point", 0 , 610);
      print("Outside Point");
      exit();
    }
    return;
  }
  NextIter();
  DisplayArray();
}

void NextIter()
{
  int last = Count;
  while (ToBeColoured < last)
  {
    int X = coloured[ToBeColoured].X;
    int Y = coloured[ToBeColoured].Y;
    ToBeColoured++;
    FillCell(X, Y, 255 - (DeltaX * k), 0, 0);

    if (X+1 < 100 && !colouredMap[X + 1][Y] && InRect(X + 1, Y))
    {
      colouredMap[X + 1][Y] = true;
      coloured[Count++] = new Point(X + 1, Y);
    }
    if (X-1 >= 0 && !colouredMap[X - 1][Y] && InRect(X - 1, Y))
    {
      colouredMap[X - 1][Y] = true;
      coloured[Count++] = new Point(X - 1, Y);
    }
    if (Y - 1 >= 0 && !colouredMap[X][Y - 1] && InRect(X, Y - 1))
    {
      colouredMap[X][Y - 1] = true;
      coloured[Count++] = new Point(X, Y - 1);
    }
    if (Y + 1 < 100 && !colouredMap[X][Y + 1] && InRect(X, Y + 1))
    {
      colouredMap[X][Y + 1] = true;
      coloured[Count++] = new Point(X, Y + 1);
    }
  }
  k++;
}

void DisplayArray()
{
  fill(255);
  rect(0, 600, 600, 100);
  stroke(0);
  fill(0);
  int StringWidth = 18;
  for (int i = 0; i < Count; i++)
  {
    if (i == ToBeColoured)
      fill(255, 0, 0);

    text(coloured[i].X, 0 + i * StringWidth, 610);
    text(coloured[i].Y, 0 + i * StringWidth, 620);

    if (i == ToBeColoured)
      fill(0);
  }
}
boolean InRect(int X, int Y)
{
  if (X >= x1 && X < x2 && Y >= y1 && Y < y2)
    return true;
  else 
    return false;
}

