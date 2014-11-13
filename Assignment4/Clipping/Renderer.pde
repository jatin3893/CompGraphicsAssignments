import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

class Renderer {
  int Width = 600, Height = 600;
  int bgRed, bgGreen, bgBlue;
  boolean initialised;
  boolean DrawGridValue;
  boolean DrawViewportValue;

  List<Geometry> objects;
  int Scale = 20;
  int[] Viewport = new int[4];

  Renderer(int Width, int Height, int Red, int Green, int Blue)
  {
    this.Width = Width;
    this.Height = Height;
    this.bgRed = Red; 
    this.bgGreen = Green; 
    this.bgBlue = Blue;
    this.initialised = false;
    this.DrawGridValue = false;
    this.DrawViewportValue = false;
    objects = new LinkedList<Geometry>();
    this.SetViewport(0, Width, 0, Height); // Default Viewport values;
  }

  void EnableDrawViewport()
  {
    this.DrawViewportValue = true;
  }

  void DisableDrawViewport()
  {
    this.DrawViewportValue = false;
  }

  void EnableDrawGrid()
  {
    this.DrawGridValue = true;
  }

  void DisableDrawGrid()
  {
    this.DrawGridValue = false;
  }

  void SetViewport(int Xmin, int Xmax, int Ymin, int Ymax)
  {
    this.Viewport[0] = Xmin;
    this.Viewport[1] = Xmax;
    this.Viewport[2] = Ymin;
    this.Viewport[3] = Ymax;
  }

  void Initialise()
  {
    size(Width, Height);
  }

  void SetPixel(int X, int Y, int r, int g, int b)
  {
    strokeWeight(0);
    fill(r, g, b, 100);
    ellipse(X * Scale + Scale / 2, Y * Scale +  + Scale / 2, 0.8 * Scale, 0.8 * Scale);
    strokeWeight(1);
  }

  void DrawViewport()
  {
    strokeWeight(2);
    stroke(255, 0, 0); // Viewport line Color Green
    line(Viewport[0] * Scale, Viewport[2] * Scale, Viewport[0] * Scale, Viewport[3] * Scale);
    line(Viewport[1] * Scale, Viewport[2] * Scale, Viewport[1] * Scale, Viewport[3] * Scale);
    line(Viewport[0] * Scale, Viewport[2] * Scale, Viewport[1] * Scale, Viewport[2] * Scale);
    line(Viewport[0] * Scale, Viewport[3] * Scale, Viewport[1] * Scale, Viewport[3] * Scale);
    strokeWeight(1);
  }

  void SetScale(int scale)
  {
    this.Scale = scale;
  }
  int GetScale()
  {
    return this.Scale;
  }
  
  void DrawGrid()
  {
    stroke(0); // Grid lines Color Black
    strokeWeight(2);
    for (int i = 0; i < Width; i += Scale)
      line(i, 0, i, Height);
    for (int i = 0; i < Height; i += Scale)
      line(0, i, Width, i);
    strokeWeight(1);
    for (int i = Scale / 2; i < Width; i += Scale)
      line(i, 0, i, Height);
    for (int i = Scale / 2; i < Height; i += Scale)
      line(0, i, Width, i);
    strokeWeight(1);
  }

  int[] GetViewport()
  {
    return this.Viewport;
  }
  
  void InsertObject(Geometry geom)
  {
    geom.SetRenderer(this);
    objects.add(geom);
  }

  void Render()
  {
    if (!initialised)
      Initialise();

    background(bgRed, bgGreen, bgBlue);
    if (DrawGridValue)
      DrawGrid();
    if (DrawViewportValue)
      DrawViewport();
    ListIterator<Geometry> listIterator = objects.listIterator();
    while (listIterator.hasNext ()) {
      listIterator.next().Render();
    }
  }
}

