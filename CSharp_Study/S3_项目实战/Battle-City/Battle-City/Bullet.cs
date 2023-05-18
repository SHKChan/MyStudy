using System;
using System.Drawing;
using System.Media;
using Battle_City.Properties;

namespace Battle_City
{
    class Bullet : MovableObejct
    {
        private static double bulletSpeed = 0.3;
        private static Bitmap[] expArr = new Bitmap[]{Resources.EXP1, Resources.EXP2, Resources.EXP3, Resources.EXP4, Resources.EXP5 };
        private SoundPlayer blastSound = new SoundPlayer(Resources.blast);
        private SoundPlayer HitSound = new SoundPlayer(Resources.hit);
        private static int expDelay = 2;
        private Tank tank;
        private int curFrame;
        private int expDelayCounter;
        private GameObject hitObj;
        public Bullet(int xx, int yy, Direction dir, Tank t) : base(xx, yy, bulletSpeed)
        {
            T = ObjType.Bullet;
            imgArr[(int)Direction.Up] = Resources.BulletUp;
            imgArr[(int)Direction.Down] = Resources.BulletDown;
            imgArr[(int)Direction.Left] = Resources.BulletLeft;
            imgArr[(int)Direction.Right] = Resources.BulletRight;
            Dir = dir;
            Img = imgArr[(int)Dir];

            isMoving = true;
            curFrame = 0;
            expDelayCounter = 0;
            hitObj = null;
            // Get more precise position via tank coordinate
            tank = t;
            x = tank.x;
            y = tank.y;
            
            blastSound = new SoundPlayer(Resources.blast);
            HitSound = new SoundPlayer(Resources.hit);

            switch (Dir)
            {
                case Direction.Up:
                    y -= BlockSize + tank.speed;
                    break;
                case Direction.Down:
                    y += BlockSize + tank.speed;
                    break;
                case Direction.Left:
                    x -= BlockSize + tank.speed;
                    break;
                case Direction.Right:
                    x += BlockSize + tank.speed;
                    break;
            }
        }

        public void Hit()
        {
            isMoving = false;
            // Display the explosion animation
            if (expDelayCounter == 0)
            {
                Img = expArr[curFrame];
                curFrame++;
                if (curFrame == expArr.Length)
                {
                    curFrame = 0;
                    tank.BulletBlast();
                    GOM.RemoveObj(hitObj);
                    GOM.RemoveObj(this);
                }
            }
            expDelayCounter = (expDelayCounter + 1) % expDelay;
        }

        private void Act()
        {
            if (isMoving)
            {
                switch (Dir)
                {
                    case Direction.Up:
                        hitObj = Move(0, -speed);
                        break;
                    case Direction.Down:
                        hitObj = Move(0, speed);
                        break;
                    case Direction.Left:
                        hitObj = Move(-speed, 0);
                        break;
                    case Direction.Right:
                        hitObj = Move(speed, 0);
                        break;
                }
                if (null != hitObj)
                {
                    isMoving = false;

                    if (tank is TankPlayer)
                    {
                        if (hitObj == this)
                        {
                            HitSound.Play();
                        }
                        else
                        {
                            blastSound.Play();
                        }

                    }

                    if (hitObj is Bullet)
                    {
                        Bullet bullet = (Bullet)hitObj;
                        bullet.Hit();
                    }
                }
            }
            else
            {
                Hit();
            }
        }

        public void Destory()
        {
            isMoving = false;
        }

        public override void Update()
        {
            Act();
            Draw();
        }

        public override Bitmap GetImage()
        {
            if (isMoving)
            {
                Img = imgArr[(int)Dir];
            }
            else
            {
                Img = expArr[curFrame];
                if (hitObj is TankNpc)
                {
                    Graphics g = Form1.graphics;
                    // Create a new Font object
                    Font font = new Font("Arial", 10);
                    // Set the color of the font
                    SolidBrush brush = new SolidBrush(Color.White);
                    // Draw the text on the form
                    g.DrawString("200 !", font, brush, new PointF(x, y));
                }
            }
            Img.MakeTransparent(Color.Black);
            return Img;
        }

        public override Rectangle GetCollisionRectangle()
        {
            return new Rectangle(x-5, y-5, 10, 10);
        }
    }
}
