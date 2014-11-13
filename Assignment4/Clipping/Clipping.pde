int MaxWidth = 600;
int MaxHeight = 600;
Renderer renderer;
int clickCount = 0;
int firstX, firstY;
boolean ViewportSelected = false;

void setup()
{
  size(MaxWidth, MaxHeight);
  renderer = new Renderer(MaxWidth, MaxHeight, 255, 255, 255);
  renderer.EnableDrawGrid();
  renderer.SetScale(30);
}

void draw()
{
  renderer.Render();
}

void mouseClicked()
{
  if (clickCount % 2 == 0)
  {
    firstX = mouseX / renderer.GetScale();
    firstY = mouseY / renderer.GetScale();
  } else
  {
    if (!ViewportSelected)
    {
      renderer.EnableDrawViewport();
      int secondX = mouseX / renderer.GetScale(), secondY = mouseY / renderer.GetScale();
      int[] bottomLeft = new int[2];
      int[] topRight = new int[2];
      if (firstX < secondX)
      {
        if (firstY < secondY)
        {
          bottomLeft[0] = firstX;
          bottomLeft[1] = firstY;
          topRight[0] = secondX;
          topRight[1] = secondY;
        } else
        {
          bottomLeft[0] = firstX;
          bottomLeft[1] = secondY;
          topRight[0] = secondX;
          topRight[1] = firstY;
        }
      } else
      {
        if (firstY > secondY)
        {
          bottomLeft[0] = secondX;
          bottomLeft[1] = secondY;
          topRight[0] = firstX;
          topRight[1] = firstY;
        } else
        {
          bottomLeft[0] = secondX;
          bottomLeft[1] = firstY;
          topRight[0] = firstX;
          topRight[1] = secondY;
        }
      }
      renderer.SetViewport(bottomLeft[0], topRight[0], bottomLeft[1], topRight[1]);
      ViewportSelected = true;
    } else
      renderer.InsertObject(new Line(firstX, firstY, mouseX / renderer.GetScale(), mouseY / renderer.GetScale()));
  }
  clickCount++;
}

