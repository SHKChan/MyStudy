using Battle_City.Properties;
using System;
using System.Drawing;

namespace Battle_City
{
    class TankNpc : Tank
    {
        private static int countStep = 25;
        private Random random;
        private int step;
        private Point preMove;

        public TankNpc(int xx, int yy, double speed, ObjType type) : base(xx, yy, speed)
        {
            T = type;
            switch (T)
            {
                case ObjType.NpcSlow:
                    imgArr[(int)Direction.Up] = Resources.SlowUp;
                    imgArr[(int)Direction.Down] = Resources.SlowDown;
                    imgArr[(int)Direction.Left] = Resources.SlowLeft ;
                    imgArr[(int)Direction.Right] = Resources.SlowRight;
                    break;
                case ObjType.NpcQuick:
                    imgArr[(int)Direction.Up] = Resources.QuickUp;
                    imgArr[(int)Direction.Down] = Resources.QuickDown;
                    imgArr[(int)Direction.Left] = Resources.QuickLeft;
                    imgArr[(int)Direction.Right] = Resources.QuickRight;
                    break;
                case ObjType.NpcGray:
                    imgArr[(int)Direction.Up] = Resources.GrayUp;
                    imgArr[(int)Direction.Down] = Resources.GrayDown;
                    imgArr[(int)Direction.Left] = Resources.GrayLeft;
                    imgArr[(int)Direction.Right] = Resources.GrayRight;
                    break;
                case ObjType.NpcGreen:
                    imgArr[(int)Direction.Up] = Resources.GreenUp;
                    imgArr[(int)Direction.Down] = Resources.GreenDown;
                    imgArr[(int)Direction.Left] = Resources.GreenLeft;
                    imgArr[(int)Direction.Right] = Resources.GreenRight;
                    break;
                case ObjType.NpcYellow:
                    imgArr[(int)Direction.Up] = Resources.YellowUp;
                    imgArr[(int)Direction.Down] = Resources.YellowDown;
                    imgArr[(int)Direction.Left] = Resources.YellowLeft;
                    imgArr[(int)Direction.Right] = Resources.YellowRight;
                    break;
            }
            Img = imgArr[(int)Dir];
            step = countStep;
            preMove = new Point(0, 0);
            random = new Random();
        }

        private void Act()
        {
            GameObject ret = null;
            if (step < countStep)
            {
                ret = Move(preMove.X, preMove.Y);
            }
            else
            {
                step = 0;
                
                if (null == bullet && random.Next(0, 100) < 20)
                {
                    Shoot();
                }

                int s = speed;

                if (random.Next(0, 100) < 50)
                {
                    s = -s;
                }
                if (random.Next(0, 100) < 50)
                {
                    if (0 > s)
                    {
                        Dir = Direction.Up;
                    }
                    else
                    {
                        Dir = Direction.Down;
                    }
                    preMove.X = 0;
                    preMove.Y = s;
                    ret = Move(0, s);
                }
                else
                {
                    if (0 > s)
                    {
                        Dir = Direction.Left;
                    }
                    else
                    {
                        Dir = Direction.Right;
                    }
                    
                    preMove.X = s;
                    preMove.Y = 0;
                    ret = Move(s, 0);
                }
            }

            step += 1;
        }

        public override void Update()
        {
            Act();
            base.Update();
        }
    }
}
