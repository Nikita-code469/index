#include <wx/wx.h> //(окна, элементы интерфейса, события, базовые типы данных)
#include <random> //для генерации псевдослучайных чисел
#include <cmath> //для вычисления корня и возведения в степень при расчете расстояния

class MyFrame : public wxFrame {
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Fleeing Button (wxWidgets)", wxDefaultPosition, wxSize(800, 600)) {

        m_btnSize = wxSize(140, 45);//размер кнопки
        m_btnPos = wxPoint(330, 255);//начальная позиция кнопки (центр окна)


        SetDoubleBuffered(true);//включает двойную буферизацию для плавной отрисовки


        Bind(wxEVT_PAINT, &MyFrame::OnPaint, this);//привязывает обработчик события рисования к этому окну
        Bind(wxEVT_MOTION, &MyFrame::OnMouseMove, this);//привязывает обработчик события движения мыши к этому окну
        Bind(wxEVT_LEFT_DOWN, &MyFrame::OnMouseClick, this);//привязывает обработчик события нажатия левой кнопки мыши к этому окну


        std::random_device rd;//источник энтропии для генерации случайных чисел
        m_gen.seed(rd());//инициализирует генератор случайных чисел с помощью энтропии от random_device
    }

private:
    wxPoint m_btnPos;//текущая позиция кнопки
    wxSize m_btnSize;//размер кнопки
    std::mt19937 m_gen;//   генератор случайных чисел (Mersenne Twister)


    bool IsMouseOverButton(const wxPoint& mousePos) {//проверяет, находится ли курсор мыши над кнопкой
        return (mousePos.x >= m_btnPos.x && mousePos.x <= m_btnPos.x + m_btnSize.GetWidth() &&//проверяет горизонтальное положение
                mousePos.y >= m_btnPos.y && mousePos.y <= m_btnPos.y + m_btnSize.GetHeight());//проверяет вертикальное положение
    }


    void Flee() {
        wxSize winSize = GetClientSize();//получает размер клиентской области окна


        std::uniform_int_distribution<> distX(10, winSize.GetWidth() - m_btnSize.GetWidth() - 10);//создает распределение для генерации случайных X координат, учитывая размер кнопки и отступы от краев окна
        std::uniform_int_distribution<> distY(10, winSize.GetHeight() - m_btnSize.GetHeight() - 10);//создает распределение для генерации случайных Y координат, учитывая размер кнопки и отступы от краев окна

        m_btnPos.x = distX(m_gen);//генерирует новую случайную X координату для кнопки
        m_btnPos.y = distY(m_gen);//генерирует новую случайную Y координату для кнопки


        Refresh();
    }


    void OnPaint(wxPaintEvent& event) {//обработчик события рисования
        wxPaintDC dc(this);//создает объект для рисования, привязанный к этому окну


        dc.SetBackground(wxBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_FRAMEBK)));// устанавливает фоновый цвет, используя системный цвет для фона окна
        dc.Clear();

    
        dc.SetBrush(wxBrush(wxColour(30, 144, 255)));//устанавливает кисть для заливки кнопки с цветом Dodger Blue
        dc.SetPen(wxPen(wxColour(0, 0, 139), 1)); //устанавливает перо для обводки кнопки с цветом Dark Blue и толщиной 1 пиксель


        dc.DrawRoundedRectangle(m_btnPos.x, m_btnPos.y, m_btnSize.GetWidth(), m_btnSize.GetHeight(), 5);//рисует закругленный прямоугольник для кнопки с радиусом скругления 5 пикселей


        dc.SetTextForeground(*wxWHITE);//устанавливает цвет текста на белый
        dc.SetFont(wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));//устанавливает шрифт для текста на кнопке (14 пунктов, без засечек, обычный стиль, жирный вес)

        wxString text = "Нажми меня!";//текст, отображаемый на кнопке
        wxSize textSize = dc.GetTextExtent(text);//получает размер текста для правильного центрирования на кнопке


        int textX = m_btnPos.x + (m_btnSize.GetWidth() - textSize.GetWidth()) / 2;//вычисляет X координату для центрирования текста на кнопке
        int textY = m_btnPos.y + (m_btnSize.GetHeight() - textSize.GetHeight()) / 2;//вычисляет Y координату для центрирования текста на кнопке
        dc.DrawText(text, textX, textY);//рисует текст на кнопке в вычисленных координатах
    }


    void OnMouseMove(wxMouseEvent& event) {//обработчик события движения мыши
        wxPoint mousePos = event.GetPosition();//получает текущую позицию курсора мыши относительно клиентской области окна


        int btnCenterX = m_btnPos.x + m_btnSize.GetWidth() / 2;//вычисляет X координату центра кнопки
        int btnCenterY = m_btnPos.y + m_btnSize.GetHeight() / 2;//вычисляет Y координату центра кнопки


        double distance = std::sqrt(std::pow(mousePos.x - btnCenterX, 2) + std::pow(mousePos.y - btnCenterY, 2));//вычисляет расстояние от курсора мыши до центра кнопки с помощью теоремы Пифагора


        if (distance < 95.0 || IsMouseOverButton(mousePos)) {//если расстояние меньше 95 пикселей или курсор находится над кнопкой, вызываем функцию Flee для перемещения кнопки в новое случайное место
            Flee();
        }
        event.Skip();//позволяет другим обработчикам событий также обрабатывать это событие, если это необходимо
    }


    void OnMouseClick(wxMouseEvent& event) {//обработчик события нажатия левой кнопки мыши
        wxPoint mousePos = event.GetPosition();//получает текущую позицию курсора мыши относительно клиентской области окна


        if (IsMouseOverButton(mousePos)) {//если курсор находится над кнопкой, отображаем сообщение о победе
            wxMessageBox("Невероятно! Вы смогли поймать и нажать кнопку!", "Победа", wxOK | wxICON_INFORMATION, this);//показывает диалоговое окно с сообщением о победе, заголовком "Победа", кнопкой OK и информационной иконкой
        }
        event.Skip();//позволяет другим обработчикам событий также обрабатывать это событие, если это необходимо
    }
};

class MyApp : public wxApp {//класс приложения, наследующий от wxApp, который является точкой входа в программу
public://переопределяет виртуальную функцию OnInit, которая вызывается при запуске приложения
    virtual bool OnInit() {//создает экземпляр главного окна (MyFrame), отображает его и возвращает true для успешной инициализации приложения
        MyFrame* frame = new MyFrame();//создает новый экземпляр главного окна
        frame->Show(true);//отображает окно на экране
        return true;//возвращает true для успешной инициализации приложения
    }
};

wxIMPLEMENT_APP(MyApp);//макрос, который реализует функцию main и запускает приложение MyApp