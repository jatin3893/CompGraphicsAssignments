int MaxWidth = 750;
int MaxHeight = 600;
int Scale = 30;

int MaxScanY = MaxHeight / Scale;
int MaxScanX = MaxWidth / Scale;
int ScanX = 0;
int ScanY = 0;

boolean Input_Ready = false;

int MaxPolygonCount = 10;
int PolygonCount = 0;
Polygon[] polygons = new Polygon[MaxPolygonCount];

void mouseClicked()
{
  if (!Input_Ready)
  {
    if (mouseButton == LEFT)
    {
      if (polygons[PolygonCount] == null)
      {
        polygons[PolygonCount] = new Polygon();
        polygons[PolygonCount].setColor(255 - PolygonCount * 50, 0, 0);
      }
      polygons[PolygonCount].insertPoint(mouseX / Scale, mouseY / Scale);
      ColorCell(mouseX / Scale, mouseY / Scale, 0, 0, 100);
      print("PointCount++");
    } else
    {
      if (PolygonCount < MaxPolygonCount)
        PolygonCount++;
      print("\nPolygonCount++\n");
    }
  }
}

void keyPressed()
{
  if (!Input_Ready && key == '\n')
  {
    Input_Ready = true;
  }
  if (Input_Ready && ScanY <= MaxScanY)
  {
    for (int i = 0; i < PolygonCount; i++)
    {
      polygons[i].draw(ScanX, ScanY);
    }
    ScanX++;
    if (ScanX == MaxScanX)
    {
      ScanY++;
      ScanX = 0;
    }
  }
}

