abstract class Geometry{
  Renderer renderer;
  void SetRenderer(Renderer ren)
  {
    this.renderer = ren;
  }
  abstract void Render();
}
