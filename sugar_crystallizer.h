#ifndef CRISTALIZADORA_H
#define CRISTALIZADORA_H
#include <QMainWindow>

namespace Ui {
  class SugarCrystallizer;
}

class SugarCrystallizer : public QMainWindow
{
  Q_OBJECT

public:
  explicit SugarCrystallizer(QWidget *parent = nullptr);
  ~SugarCrystallizer();

private slots:
  /// QRadioButtons
  void on_radioButton_todosOK_clicked();
  void on_radioButton_I_roto_clicked();
  void on_radioButton_II_roto_clicked();
  void on_radioButton_todosRotos_clicked();

  void on_comboBox_currentIndexChanged(int index);

  void on_dial_principal_valueChanged(int value);

  /// Tacho I
  void on_dial_tachoI_valueChanged(int value);
  void on_spinBox_tachoI_valueChanged(const QString &arg1);
  void on_spinBox_tachoI_valueChanged(int arg1);

  /// Tacho II

  void on_verticalSlider_valueChanged();

  void on_progressBar_valueChanged(int value);

private:
  Ui::SugarCrystallizer *ui;
};

#endif // CRISTALIZADORA_H
