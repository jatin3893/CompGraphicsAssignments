Car myCar;
int MaxHeight = 600;
int MaxWidth = 1350;

int sky[] = {
  135, 206, 250
};
boolean DayToNight = true;
boolean Rain = true;
int CloudX = 0;

void setup()
{
  // Initialise Car
  myCar = new Car();

  // Initialise Window
  size(MaxWidth, MaxHeight);
}

void draw()
{
  background(0, 0, 0);
  noStroke();

  if (sky[0] == 0 && sky[1] == 0 && sky[2] == 0)
  {
    DayToNight = false;
  } else if (sky[0] == 135 && sky[1] == 206 && sky[2] == 250)
  {
    DayToNight = true;
  }
  if ((int)random(1000) > 900)
    Rain = true;
  else if ((int)random(1000) < 100)
    Rain = false;

  if ((int)random(4) % 2 == 0)
  {
    if (DayToNight == true)
    {
      sky[0] = sky[0] > 0 ? sky[0] - 1 : 0;
      sky[1] = sky[1] > 0 ? sky[1] - 1 : 0;
      sky[2] = sky[2] > 0 ? sky[2] - 1 : 0;
    } else
    {
      sky[0] = sky[0] < 135 ? sky[0] + 4 : 135;
      sky[1] = sky[1] < 206 ? sky[1] + 2 : 206;
      sky[2] = sky[2] < 250 ? sky[2] + 1 : 250;
    }
  }

  strokeWeight(10);
  stroke(0, 0, 255);
  for (int i = 0; i < 1000; i++)
  {
    int tempX = (int)random(MaxHeight);
    int tempY = (int)random(MaxWidth);
    line(tempX, tempY, tempX + 5, tempY + 5);
  }
  noStroke();

  fill(sky[0], sky[1], sky[2]);
  rect(0, 0, MaxWidth, MaxHeight * 0.4); // Sky
  fill(255, 255, 255);
  ellipse((CloudX + 80) % MaxWidth, 15, 150, 60);
  ellipse((CloudX + 150) % MaxWidth,  15, 80, 40);
  ellipse((CloudX + 110) % MaxWidth,  50, 100, 50);
  ellipse((CloudX + 70) % MaxWidth,  40, 120, 40);

  ellipse((CloudX + 380) % MaxWidth,  75, 150, 60);
  ellipse((CloudX + 450) % MaxWidth,  75, 80, 40);
  ellipse((CloudX + 310) % MaxWidth,  100, 100, 50);
  ellipse((CloudX + 370) % MaxWidth,  90, 120, 40);
  
  ellipse((CloudX + 580) % MaxWidth,  15, 150, 60);
  ellipse((CloudX + 550) % MaxWidth,  15, 80, 40);
  ellipse((CloudX + 610) % MaxWidth,  50, 100, 50);
  ellipse((CloudX + 510) % MaxWidth,  40, 120, 40);

  ellipse((CloudX + 1080) % MaxWidth,  60, 150, 60);
  ellipse((CloudX + 1050) % MaxWidth,  75, 80, 40);
  ellipse((CloudX + 1010) % MaxWidth,  100, 100, 50);
  ellipse((CloudX + 1070) % MaxWidth,  90, 120, 40);
  CloudX = (CloudX + 1) % MaxWidth;
  
  fill(0, 104, 10);
  rect(0, MaxHeight * 0.4, MaxWidth, MaxHeight * 0.6); // Grass
  fill(51, 51, 51);
  rect(0, MaxHeight * 0.6, MaxWidth, MaxHeight * 0.35); // Road


  myCar.draw();
  myCar.setAcceleration( (mouseX - myCar.getX()) / 750.0 );
}

void mouseClicked()
{
  print(mouseX + " " + mouseY + "\n");
}

