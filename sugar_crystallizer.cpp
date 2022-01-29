#include "sugar_crystallizer.h"
#include "ui_sugar_crystallizer.h"
#include <QTimer>

SugarCrystallizer::SugarCrystallizer(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::SugarCrystallizer)
{
  ui->setupUi(this);

  /// Para evitar que se modifique los spinBox
  ui->spinBox_princp->setReadOnly(true);
  ui->spinBox_tachoI->setReadOnly(true);
  ui->spinBox_tachoII->setReadOnly(true);

  /// Deshabilitamos todo hasta que se selecc un radioButton
  ui->groupBox->setDisabled(true);
  ui->groupBox_2->setDisabled(true);
  ui->dial_principal->setDisabled(true);
  ui->lineEdit->setDisabled(true);
  ui->comboBox->setDisabled(true);

  // cambiamos el largo del lineEdit
  ui->lineEdit->setMaxLength(30);
}

SugarCrystallizer::~SugarCrystallizer(){  delete ui; }

void SugarCrystallizer::on_dial_principal_valueChanged(int dial_vp_value){
  int v1 = ui->dial_tachoI->value();
  int v2 = ui->dial_tachoII->value();
  
  // corrige el valor de flujo de v1
  // si la suma de los spinBoxes de los tachos I y II es mayor
  // que el valor de la val principal
  if((v1 + v2) <= dial_vp_value){
    return;
  } else {
    ui->spinBox_tachoI->setValue(vP - v2);
  }
}

// If all "tachos" are working fine
void SugarCrystallizer::on_radioButton_todosOK_clicked(){
  ui->groupBox->setDisabled(false);
  ui->groupBox_2->setDisabled(false);
  ui->dial_main_valv->setDisabled(false);
  ui->lineEdit_log->setDisabled(false);
  ui->comboBox_select_tacho->setDisabled(false);
}

// If "tacho I" is not working
void SugarCrystallizer::on_radioButton_I_roto_clicked(){
  ui->groupBox_tacho_I->setDisabled(true);
  ui->groupBox_tacho_II->setDisabled(false);
  ui->dial_main_valv->setDisabled(false);
  ui->lineEdit_log->setDisabled(false);
  ui->comboBox_select_tacho->setDisabled(false);
}

// If "tacho II" is not working
void SugarCrystallizer::on_radioButton_II_roto_clicked(){
  ui->groupBox_tacho_I->setDisabled(false);
  ui->groupBox_tacho_II->setDisabled(true);
  ui->dial_main_valv->setDisabled(false);
  ui->lineEdit_log->setDisabled(false);
  ui->comboBox_select_tacho->setDisabled(false);
}

// If all "tachos" are not working
void SugarCrystallizer::on_radioButton_todosRotos_clicked(){
  ui->groupBox_tacho_I->setDisabled(true);
  ui->groupBox_tacho_II->setDisabled(true);
  ui->dial_main_valv->setDisabled(true);
  ui->lineEdit_log->setDisabled(true);
  ui->comboBox_select_tacho->setDisabled(true);
}

void SugarCrystallizer::on_comboBox_currentIndexChanged(int index){
  switch (index) {
    case 0:
      ui->lcdNumber->display(0);
      ui->lcdNumber->setDisabled(true);
      break;
    case 1:
      ui->lcdNumber->setDisabled(false);
      ui->lcdNumber->display(ui->spinBox_tachoI->value() * 2);
      break;
    case 2:
      ui->lcdNumber->setDisabled(false);
      ui->lcdNumber->display(ui->spinBox_tachoII->value() * 2);
      break;
    default:
      ui->lcdNumber->setDisabled(true);
      break;
    }
}

/*
* Tacho I
*/

void SugarCrystallizer::on_verticalSlider_valueChanged(){
  ui->dial_tachoI->setValue(99);
}

void SugarCrystallizer::on_spinBox_tachoI_valueChanged(int spinB_value){
  if(ui->comboBox->currentIndex() == 1){
    ui->lcdNumber->display(spinB_value * 2); // to L/s
  }
}

void SugarCrystallizer::on_dial_tachoI_valueChanged(int dialValue){
//  qint8 v2 = ui->spinBox_princp->value() - value;
//  ui->spinBox_tachoII->setValue(v2);

  ui->spinBox_tachoI->setValue(dialValue);
//  ui->progressBar->setValue(100);
//  QTimer temporizador;
//  temporizador.start(10);
}

// Liquid level on "Tacho I"
void SugarCrystallizer::on_progressBar_valueChanged(int value){
  if(value == 100){
    ui->verticalSlider->setValue(0);
  }
}

/*
*  Logging
*/

void SugarCrystallizer::on_spinBox_tachoI_valueChanged(const QString &arg1){
  QString str = ui->lineEdit->text();

  // si str es mas largo que el max de caracteres que
  // soporta el lineEdit
  if((str.length() + 4) <= ui->lineEdit->maxLength()){
    if(str == ""){
      ui->lineEdit->setText(arg1);
      return;
    } else {
      str += ", " + arg1;  // puedes usar str.append(", " + arg1);
      ui->lineEdit->setText(str);
      return;
    }
  } else {
    str.remove(0,4);
    if((str.length() + 4) <= ui->lineEdit->maxLength()){
      str += ", " + arg1;
      ui->lineEdit->setText(str);
    } else {
      ui->statusBar->showMessage("problemas con el largo de la cadena en"
                                 "el line edit");
    }

  }
}