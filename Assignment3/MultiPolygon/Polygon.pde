class Polygon
{
  int MaxPointCount = 10;
  int PointCount = 0;
  int[][] Points = new int[MaxPointCount][2];
  int[] Color = new int[3];
  int CurY = -1;
  boolean CurColor = false;

  int[] intersectionList;
  int IntersectionCount = 0;

  void setColor(int r, int g, int b)
  {
    Color[0] = r;
    Color[1] = g;
    Color[2] = b;
  }
  void insertPoint(int x, int y)
  {
    if (PointCount < MaxPointCount)
    {
      Points[PointCount][0] = x;
      Points[PointCount][1] = y;
      PointCount++;
    }
  }
  void CreateIntersectionList()
  {
    intersectionList = new int[PointCount];
    IntersectionCount = 0;
    for (int i = 0; i < PointCount; i++)
    {
      int[] Top = new int[2], Bottom = new int[2];
      if (Points[(i + 1) % PointCount][1] > Points[i % PointCount][1])
      {
        Top[0] = Points[(i + 1) % PointCount][0];
        Top[1] = Points[(i + 1) % PointCount][1];
        Bottom[0] = Points[i % PointCount][0];
        Bottom[1] = Points[i % PointCount][1];
      } else
      {
        Bottom[0] = Points[(i + 1) % PointCount][0];
        Bottom[1] = Points[(i + 1) % PointCount][1];
        Top[0] = Points[i % PointCount][0];
        Top[1] = Points[i % PointCount][1];
      }
      if (CurY <= Top[1] && CurY >= Bottom[1])
      {
        float m_1;
        m_1 = ((float)(Top[0] - Bottom[0])) / (Top[1] - Bottom[1]);
        float xPos = (CurY - Bottom[1]) * m_1 + Bottom[0];
        int x = (int)xPos;
        if (ScanY != Top[1])
        {
          intersectionList[IntersectionCount++] = x;
        }
      }
    }
    for (int i = 0; i < IntersectionCount; i++)
    {
      for (int j = i + 1; j < IntersectionCount; j++)
      {
        if (intersectionList[i] > intersectionList[j])
        {
          int temp = intersectionList[i];
          intersectionList[i] = intersectionList[j];
          intersectionList[j] = temp;
        }
      }
    }
    for (int i = 0; i < IntersectionCount; i++)
    {
      print(intersectionList[i] + " ");
    }
    print("\n");
  }
  void draw(int X, int Y)
  {
    for (int i = 0; i < IntersectionCount; i++)
    {
      print(intersectionList[i] + " ");
    }
    print("\n");
    if (CurY == Y)
    {
      int i = 0;
      while (i < IntersectionCount && X > intersectionList[i])
      {
        i++;
      }
      if (i % 2 == 1)
      {
        fill(Color[0], Color[1], Color[2]);
        ellipse(X * Scale, Y * Scale, Scale, Scale);
      }
    } else {
      CurY = Y;
      CreateIntersectionList();
    }
  }
}

