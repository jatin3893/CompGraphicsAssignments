int MaxWidth = 750;
int MaxHeight = 600;
int Scale = 30;
boolean Input_Ready = false;
boolean ColorOn = false;
int MaxScanY = MaxHeight / Scale;
int MaxScanX = MaxWidth / Scale;
int ScanX = 0;
int ScanY = 0;

int PointCount = 0;
int MaxPointCount = 20;
int[] X = new int[MaxPointCount];
int[] Y = new int[MaxPointCount];

int[] ScanLineIntersectionList;
int IntersectionCount = 0;
int Cur = 0;

void initialiseGrid()
{
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
  rect(x * Scale, y * Scale, Scale, Scale);
}
void setup()
{
  size(MaxWidth, MaxHeight);
  background(255);
  UpdateScanLineIntersectionList();
  initialiseGrid();
}

void draw()
{
  keyPressed();
  DrawInputPoints();
}

void DrawInputPoints()
{
  for (int i = 0; i < PointCount; i++)
    ColorCell(X[i], Y[i], 0, 100, 100);
}

void UpdateScanLineIntersectionList()
{
  for (int i = 0; i < PointCount; i++)
  {
    int[] Top = new int[2], Bottom = new int[2];
    if (Y[(i + 1) % PointCount] > Y[i % PointCount])
    {
      Top[0] = X[(i + 1) % PointCount];
      Top[1] = Y[(i + 1) % PointCount];
      Bottom[0] = X[i % PointCount];
      Bottom[1] = Y[i % PointCount];
    } else
    {
      Bottom[0] = X[(i + 1) % PointCount];
      Bottom[1] = Y[(i + 1) % PointCount];
      Top[0] = X[i % PointCount];
      Top[1] = Y[i % PointCount];
    }
    if (ScanY <= Top[1] && ScanY >= Bottom[1])
    {
      float m_1;

      m_1 = ((float)(Top[0] - Bottom[0])) / (Top[1] - Bottom[1]);
      float xPos = (ScanY - Bottom[1]) * m_1 + Bottom[0];
      int x;
      if (xPos - (int)xPos > 0 && xPos - (int)xPos <= 0.5)
        x = (int)xPos;
      else
        x = (int)xPos + 1;
      if (ScanY != Bottom[1])
      {
        ScanLineIntersectionList[IntersectionCount++] = x;
      }
    }
  }
  for (int i = 0; i < IntersectionCount; i++)
  {
    for (int j = i + 1; j < IntersectionCount; j++)
    {
      if (ScanLineIntersectionList[i] > ScanLineIntersectionList[j])
      {
        int temp = ScanLineIntersectionList[i];
        ScanLineIntersectionList[i] = ScanLineIntersectionList[j];
        ScanLineIntersectionList[j] = temp;
      }
    }
  }
}

void mouseClicked()
{
  if (mouseButton == LEFT)
  {
    if (PointCount < MaxPointCount)
    {
      X[PointCount] = mouseX / Scale;
      Y[PointCount++] = mouseY / Scale;
      DrawInputPoints();
    }
  } else
  {
    ScanLineIntersectionList = new int[PointCount];
    Input_Ready = true;
  }
}
void keyPressed()
{
  if (Input_Ready)
  {
    if (ScanY <= MaxScanY)
    {
      if (Cur < IntersectionCount && ScanX >= ScanLineIntersectionList[Cur])
      {
        ColorOn = !ColorOn;
        Cur++;
      }
      if (ColorOn)
        ColorCell(ScanX, ScanY, 0, 0, 100);
      else
        ColorCell(ScanX, ScanY, 100, 0, 0);
      ScanX++;
      if (ScanX == MaxScanX)
      {
        ScanY++;
        ScanX = 0;
        IntersectionCount = 0;
        UpdateScanLineIntersectionList();
        Cur = 0;
      }
    }
  }
}

