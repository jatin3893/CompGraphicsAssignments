class Car {
  private int X;
  private int Y;
  private int CarHeight = 100;
  private float acceleration;
  private float velocity;
  private int displacement;
  private float friction = 0.4;
  private Wheels rear;
  private Wheels front;

  public Car()
  {
    this(50, MaxHeight);
  }

  public Car(int _X, int _Y)
  {
    X = _X;
    Y = _Y - CarHeight;
    acceleration = 0;
    rear = new Wheels(X, Y, 50);
    front = new Wheels(X + 200, Y, 50);
  }
  public void draw()
  {
    // Draw Car Body
    pushMatrix();
    translate(X - 50, Y);
    
    fill(255, 0, 0);
    ellipse(240, -215, 30, 30);
    fill(255, 0, 0, 10 * ((int)random(100) % 10));  
    ellipse(240, -220, 45, 45);

    stroke(0);
    fill(0, 0, 0, 150);
    strokeWeight(20);
    stroke(10, 0, 50);
    beginShape();
    curveVertex(100, -100);
    curveVertex(0, -100);
    curveVertex(100, -200);
    curveVertex(260, -200);
    curveVertex(320, -100);
    curveVertex(325, -100);
    curveVertex(100, -100);
    curveVertex(100, -100);
    endShape();
    line(50, -162, 50, -100);
    line(180, -205, 180, -100);

    fill(10, 0, 50);
    strokeWeight(5);
    beginShape();
    curveVertex(0, 20);
    curveVertex(0, 20);
    curveVertex(300, 20);
    curveVertex(400, 0);
    curveVertex(380, -100);
    curveVertex(0, -100);
    curveVertex(0, 0);
    curveVertex(0, 0);
    endShape();

    // Draw Stripes
    strokeWeight(2);
    stroke(255);
    beginShape();
    curveVertex(-25, 0);
    curveVertex(-25, -80);
    curveVertex(400, -80);
    curveVertex(400, 0);
    endShape();
    
    strokeWeight(6);
    stroke(255);
    beginShape();
    curveVertex(-25, 0);
    curveVertex(-25, -75);
    curveVertex(400, -75);
    curveVertex(400, 0);
    endShape();
    
    line(70, -100, 85, -101);
    line(195, -101, 210, -101);

    // Draw Lights
    noStroke();
    fill(255, 255, 0);
    ellipse(415, -75, 30, 40);
    fill(255);
    rect(410, -25, 10, 40);
    
    // Write Name
    text("Police", -5, -65);
    
    translate(-X + 50, -Y);
    popMatrix();
    
    // Draw Tires
    front.draw();
    rear.draw();

    // Update Car position
    this.updatePosition();

    // Update Tire positions
    rear.Translate(displacement);
    front.Translate(displacement);
  }
  public void updatePosition()
  {
    if (velocity > 0.2)
      velocity = velocity + acceleration - friction;
    else if (velocity < -0.2)
      velocity = velocity + acceleration + friction;
    else
      velocity = velocity + acceleration;

    displacement = (int)velocity;
    this.X = X + displacement;
  }
  public void setAcceleration(float acc)
  {
    this.acceleration = acc;
  }
  public int getX()
  {
    return X;
  }
}

