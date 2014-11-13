class Line extends Geometry 
{
  int[] Color;
  int x1, y1;
  int x2, y2;
  int clipX1, clipY1;
  int clipX2, clipy2;
  int[] VertexColor = {
    255, 0, 0
  };
  int[] OrigColor = {
    0, 255, 0
  };
  int LineMode;

  Line(int x1, int y1, int x2, int y2)
  {
    if (x1 <= x2)
    {
      this.x1 = x1;
      this.y1 = y1;
      this.x2 = x2;
      this.y2 = y2;
    } else {
      this.x1 = x2;
      this.y1 = y2;
      this.x2 = x1;
      this.y2 = y1;
    }
  }

  void Render()
  {
    // Draw start end points
    this.renderer.SetPixel(x1, y1, VertexColor[0], VertexColor[1], VertexColor[2]);
    this.renderer.SetPixel(x2, y2, VertexColor[0], VertexColor[1], VertexColor[2]);

    // Draw Original Line
    RenderOriginal();

    // Draw Clipped Line
    RenderClipped();
  }

  void RenderOriginal()
  {
    DrawLine(x1, y1, x2, y2, 0, 255, 0);
  }

  void RenderClipped()
  {
    int[][] Normal = new int[4][2];
    Normal[0][0] = 0;  
    Normal[0][1] = -1;
    Normal[1][0] = 1;  
    Normal[1][1] = 0;
    Normal[2][0] = 0;  
    Normal[2][1] = 1;
    Normal[3][0] = -1;  
    Normal[3][1] = 0;
    int[][] EdgePoint = new int[4][2];
    int[] Viewport = renderer.GetViewport();
    EdgePoint[0][0] = Viewport[0];  
    EdgePoint[0][1] = Viewport[2];
    EdgePoint[1][0] = Viewport[1];  
    EdgePoint[1][1] = Viewport[3];
    EdgePoint[2][0] = Viewport[1];  
    EdgePoint[2][1] = Viewport[3];
    EdgePoint[3][0] = Viewport[0];  
    EdgePoint[3][1] = Viewport[2];

    int[] D = new int[2];
    D[0] = x2 - x1; 
    D[1] = y2 - y1;
    float tE = 0, tL = 1;

    for (int i = 0; i < 4; i++)
    {
      float Ni_DOT_D = Normal[i][0] * D[0] + Normal[i][1] * D[1];
      if (Ni_DOT_D == 0)
        continue;
      float Ni_DOT_Pi_Pe = Normal[i][0] * (x1 - EdgePoint[i][0]) + Normal[i][1] * (y1 - EdgePoint[i][1]);
      float t = (-Ni_DOT_Pi_Pe / Ni_DOT_D);
      if (Ni_DOT_D < 0)
      {
        tE = tE > t ? tE : t;
      } else
      {
        tL = tL < t ? tL : t;
      }
    }
    if (tE > tL)
    {
      print("Trivial Reject");
      return;
    }
    float startX = (1 - tE) * x1 + tE * x2;
    float startY = (1 - tE) * y1 + tE * y2;
    float endX = (1 - tL) * x1 + tL * x2;
    float endY = (1 - tL) * y1 + tL * y2;
    DrawLine((int)startX, (int)startY, (int)endX, (int)endY, 0, 0, 255);
  }

  void DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b)
  {
    int tempX1 = 0, tempY1 = 0, tempX2 = 0, tempY2 = 0;
    float slope = ((float)(y2 - y1)) / (x2 - x1);
    int dx = 0, dy = 0, x = 0, y = 0;
    if (slope >= 0 && slope <= 1)
    {
      LineMode = 1; //  Slope 0 to 1
      tempX1 = x1;
      tempY1 = y1;
      tempX2 = x2;
      tempY2 = y2;
    } else if (slope > 1)
    {
      LineMode = 2; // Slope 1 to Inf
      tempX1 = y1;
      tempY1 = x1;
      tempX2 = y2;
      tempY2 = x2;
    } else if (slope < -1)
    {
      LineMode = 3; // Slope -1 to -Inf
      tempX1 = -y1;
      tempX2 = -y2;
      tempY1 = x1;
      tempY2 = x2;
    } else
    {
      LineMode = 4; // SLope 0 to -1
      tempX1 = x1;
      tempY1 = -y1;
      tempX2 = x2;
      tempY2 = -y2;
    }

    dx = tempX2 - tempX1;
    dy = tempY2 - tempY1;
    x = tempX1;
    y = tempY1;
    int d = 2 * dy - dx;
    int incrE = 2 * dy;
    int incrNE = 2 * (dy - dx);

    while (x + 1< tempX2)
    {
      if (d <= 0)
      {
        d += incrE;
      } else
      {
        d += incrNE;
        y++;
      }
      x++;
      switch(LineMode)
      {
      case 1:
        this.renderer.SetPixel(x, y, r, g, b);
        break;
      case 2:
        this.renderer.SetPixel(y, x, r, g, b);
        break;
      case 3:
        this.renderer.SetPixel(y, -x, r, g, b);
        break;
      case 4:
        this.renderer.SetPixel(x, -y, r, g, b);
        break;
      }
    }
  }
}

