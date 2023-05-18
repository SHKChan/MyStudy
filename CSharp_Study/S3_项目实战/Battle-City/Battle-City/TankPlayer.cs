using Battle_City.Properties;
using System.Windows.Forms;

namespace Battle_City
{
    class TankPlayer : Tank
    {
        public TankPlayer(int xx, int yy, double speed) : base(xx, yy, speed)
        {
            imgArr[(int)Direction.Up] = Resources.MyTankUp;
            imgArr[(int)Direction.Down] = Resources.MyTankDown;
            imgArr[(int)Direction.Left] = Resources.MyTankLeft;
            imgArr[(int)Direction.Right] = Resources.MyTankRight;
            T = ObjType.Player;
            Img = imgArr[(int)Dir];
        }

        public void HandleInput()
        {
            if (isMoving)
            {
                switch (Dir)
                {
                    case Direction.Up:
                        Move(0, -speed);
                        break;
                    case Direction.Down:
                        Move(0, speed);
                        break;
                    case Direction.Left:
                        Move(-speed, 0);
                        break;
                    case Direction.Right:
                        Move(speed, 0);
                        break;
                }
            }
        }

        public override void Update()
        {
            HandleInput();
            base.Update();
        }

        public void OnKeyDown(KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Up:
                    Dir = Direction.Up;
                    isMoving = true;
                    break;
                case Keys.Down:
                    Dir = Direction.Down;
                    isMoving = true;
                    break;
                case Keys.Left:
                    Dir = Direction.Left;
                    isMoving = true;
                    break;
                case Keys.Right:
                    Dir = Direction.Right;
                    isMoving = true;
                    break;
                case Keys.Space:
                    if (null == bullet)
                    {
                        Shoot();
                    }
                    break;
            }
        }

        public void OnKeyUp(KeyEventArgs e)
        {
            isMoving = false;
        }
    }
}
