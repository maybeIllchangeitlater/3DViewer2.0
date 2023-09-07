QMainWindow {
   font: 18pt  'Tahoma';
   background-color: #121212;
}

QLabel {
   font: 16pt 'Tahoma';
   color: #ffffff;
}

QLineEdit {
  font: 18pt 'Tahoma';
  color: #ffffff;
  background-color: #333333;
  border: 1px solid #afafaf;
  border-radius: 4px;
}


QCheckBox {
    font: 15pt  'Tahoma';
    color: #ffffff;
    padding: 5px;
}

QCheckBox::indicator:unchecked {
    background-color: #333333;
    border: 1px solid #333333;
    border-radius: 9px;
}

QCheckBox::indicator:unchecked:hover {
    background-color: #333333;
    border: 1px solid #6CD2E9;
}

QCheckBox::indicator:unchecked:pressed {
    background-color: #6CD2E9;
    border: 1px solid #6CD2E9;
}

QCheckBox::indicator:checked {
    background: qradialgradient(cx:0.5, cy:0.5, radius: 1,
                fx:0.5, fy:0.5, stop:0 black, stop:1 #6AD2E9);
    border: 1px solid #6CD2E9;
    border-radius: 9px;
}


QCheckBox::indicator:checked:pressed {
    background-color: #333333;
    border: 1px solid #afafaf;
}



QPushButton {
  font: 18pt  'Tahoma';
  color: #ffffff;
  background-color: #1f1f1f;
  border-radius: 4px;
  border-color: #121212;
  padding: 4px;
}

QPushButton:hover {
  background: qradialgradient(cx:0.5, cy:0.5, radius: 1,
            fx:0.5, fy:0.5, stop:0 black, stop:1 #6AD2E9);
  border: 1px solid #6CD2E9;
  border-radius: 4px;
}

QPushButton:pressed {
  background-color: #333333;
  border-color: #afafaf;
}

QSlider::groove:horizontal {
    border-radius: 1px;
    height: 7px;
    margin: -1px 0;
}

QSlider::handle:horizontal {
    background-color: #ffffff;
    border: 1px solid #ffffff;
    height: 8px;
    width: 4px;
    margin: -4px 0;
    border-radius: 2px;
    padding: -4px 0px;
}

QSlider::add-page:horizontal {
    background: #333333;
}

QSlider::sub-page:horizontal {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 rgba(150, 230, 255, 0), stop: 0.7 rgba(106, 210, 233, 190),
                stop:1 rgba(150, 230, 255, 190));
}
