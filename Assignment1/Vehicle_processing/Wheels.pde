class Wheels
{
  private int X;
  private int Y;
  private int Radius;
  private float Rotation;

  public Wheels(int X, int Y, int Radius)
  {
    this.X = X;
    this.Y = Y;
    this.Radius = Radius;
    this.Rotation = 0;
  }

  public Wheels()
  {
    this(0, 0, 0);
  }

  void SetPosition(int X, int Y)
  {
    this.X = X;
    this.Y = Y;
  }

  void SetRotation(float rotation)
  {
    this.Rotation = rotation % 360;
  }

  void SetRadius(int Radius)
  {
    this.Radius = Radius;
  }

  void Translate(int displacement)
  {
    this.Rotation += (float)displacement / Radius;
    this.SetPosition(X + displacement, Y);
  }

  void draw()
  {
    stroke(0, 0, 0);
    strokeWeight(2);
    fill(0);
    ellipse(X, Y, Radius * 2.25, Radius * 2.25);
    fill(25);
    ellipse(X, Y, Radius * 2, Radius * 2);
    
    pushMatrix();
    translate(this.X, Y);
    rotate(Rotation);
    strokeWeight(2);
    fill(0);
    beginShape();
    vertex(0, -50);
    vertex(14, -20);
    vertex(47, -15);
    vertex(23, 7);
    vertex(29, 40);
    vertex(0, 25);
    vertex(-29, 40);
    vertex(-23, 7);
    vertex(-47, -15);
    vertex(-14, -20);
    endShape(CLOSE);
    translate(-this.X, -Y);
    popMatrix();
    fill(255);
    ellipse(X, Y, 25, 25);
  }
}

