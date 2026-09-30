#include <wx/wx.h> //(базовые классы, окна, события, стандартные компоненты)
#include <wx/timer.h> //для работы с таймерами

class BallFrame : public wxFrame {
public:
    BallFrame() : wxFrame(nullptr, wxID_ANY, "Анимация: Шарик (wxWidgets)", wxDefaultPosition, wxSize(800, 600)) {

        SetBackgroundColour(wxColour(15, 15, 25));


        SetDoubleBuffered(true); //двойная буферизация для предотвращения мерцания


        m_radius = 25; //радиус шарика
        m_ballPos = wxPoint(400, 300); //начальные координаты центра шарика


        m_velocityX = 5; //скорость по горизонтали
        m_velocityY = 4; //скорость по вертикали


        Bind(wxEVT_PAINT, &BallFrame::OnPaint, this); //привязывает обработчик события рисования к этому окну


        m_timer = new wxTimer(this, wxID_ANY); //Создает таймер и связывает его с этим окном
        Bind(wxEVT_TIMER, &BallFrame::OnTimer, this); //привязывает обработчик таймера к этому окну
        

        m_timer->Start(16); //Запускает таймер
    }


    ~BallFrame() { //уничтожает таймер
        if (m_timer->IsRunning()) {
            m_timer->Stop();
        }
        delete m_timer;
    }

private:
    wxTimer* m_timer; //Указатель
    wxPoint m_ballPos; //положение центра шарика
    int m_radius; //хранения радиуса шарика
    int m_velocityX; //скорости по X
    int m_velocityY; //скорости по Y


    void OnPaint(wxPaintEvent& event) { //отрисовка
        wxPaintDC dc(this);//привязанный к текущему окну
        dc.Clear();//очищает фон цвет


        dc.SetBrush(wxBrush(wxColour(50, 205, 50))); //цвет шара
        dc.SetPen(wxPen(wxColour(34, 139, 34), 2));//контур шара


        dc.DrawCircle(m_ballPos, m_radius);//рисует шар 
    }


    void OnTimer(wxTimerEvent& event) {//физика

        wxSize winSize = GetClientSize();//рамеры окна
        int width = winSize.GetWidth();//ширина
        int height = winSize.GetHeight();//высота


        m_ballPos.x += m_velocityX;//обновляет X
        m_ballPos.y += m_velocityY;//обновляет Y


        if (m_ballPos.x - m_radius < 0) {//столкновение слева
            m_ballPos.x = m_radius;//не вылет за левый край
            m_velocityX = -m_velocityX;//меняет направление
        } 
        else if (m_ballPos.x + m_radius > width) { //столкновение справа
            m_ballPos.x = width - m_radius;
            m_velocityX = -m_velocityX;
        }


        if (m_ballPos.y - m_radius < 0) {//столкновение сверху
            m_ballPos.y = m_radius;
            m_velocityY = -m_velocityY;
        } 
        else if (m_ballPos.y + m_radius > height) {// столкновение снизу
            m_ballPos.y = height - m_radius;
            m_velocityY = -m_velocityY;
        }


        Refresh();
    }
};

class BallApp : public wxApp {
public:
    virtual bool OnInit() {
        BallFrame* frame = new BallFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(BallApp);