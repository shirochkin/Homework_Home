#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), view{new QTableView()}
{
    //Исходное состояние виджетов
    ui->setupUi(this);
    ui->lb_statusConnect->setStyleSheet("color:red");
    ui->pb_request->setEnabled(false);

    /*
     * Выделим память под необходимые объекты. Все они наследники
     * QObject, поэтому воспользуемся иерархией.
    */

    dataDb = new DbData(this);
    dataBase = new DataBase(this);
    msg = new QMessageBox(this);

    //Установим размер вектора данных для подключения к БД
    dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);

    /*
     * Добавим БД используя стандартный драйвер PSQL и зададим имя.
    */
    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    /*
     * Устанавливаем данные для подключениея к БД.
     * Поскольку метод небольшой используем лямбда-функцию.
     */
    connect(dataDb, &DbData::sig_sendData, this, [&](QVector<QString> receivData){
        dataForConnect = receivData;
    });

    /*
     * Соединяем сигнал, который передает ответ от БД с методом, который отображает ответ в ПИ
     */
     connect(dataBase, &DataBase::sig_SendDataFromDB, this, &MainWindow::ScreenDataFromDB);

    /*
     *  Сигнал для подключения к БД
     */
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete view;
}

/*!
 * @brief Слот отображает форму для ввода данных подключения к БД
 */
void MainWindow::on_act_addData_triggered()
{
    //Отобразим диалоговое окно. Какой метод нужно использовать?
    dataDb->show();
}

/*!
 * @brief Слот выполняет подключение к БД. И отображает ошибки.
 */

void MainWindow::on_act_connect_triggered()
{
    /*
     * Обработчик кнопки у нас должен подключаться и отключаться от БД.
     * Можно привязаться к надписи лейбла статуса. Если он равен
     * "Отключено" мы осуществляем подключение, если "Подключено" то
     * отключаемся
    */

    if(ui->lb_statusConnect->text() == "Отключено"){

       ui->lb_statusConnect->setText("Подключение");
       ui->lb_statusConnect->setStyleSheet("color : black");


       auto conn = [&]{dataBase->ConnectToDataBase(dataForConnect);};
       QtConcurrent::run(conn);

    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        ui->lb_statusConnect->setText("Отключено");
        ui->act_connect->setText("Подключиться");
        ui->lb_statusConnect->setStyleSheet("color:red");
        ui->pb_request->setEnabled(false);
    }

}

/*!
 * \brief Обработчик кнопки "Получить"
 */
void MainWindow::on_pb_request_clicked()
{
    if(ui->cb_category->currentText() == "Все"){
    emit dataBase->sig_SendDataFromDB(ui->tb_result, 1);
    }

    else if (ui->cb_category->currentText() == "Комедия"){
        emit dataBase->sig_SendDataFromDB(ui->tb_result, 2);
    }

    else if (ui->cb_category->currentText() == "Ужасы"){
        emit dataBase->sig_SendDataFromDB(ui->tb_result, 3);
    }

}

/*!
 * \brief Слот отображает значение в QTableWidget
 * \param widget
 * \param typeRequest
 */
void MainWindow::ScreenDataFromDB(QTableWidget *widget, int typeRequest)
{
    view-> setParent(widget);
    view->setMinimumWidth(750);
    view->setMinimumHeight(500);
    QSqlQueryModel* q_model = new QSqlQueryModel(widget);
    q_model->setHeaderData(0, Qt::Horizontal, tr("Title"));
    q_model->setHeaderData(1, Qt::Horizontal, tr("Description"));
    QSqlTableModel* t_model = new QSqlTableModel(widget, dataBase->getDB());
    t_model->setTable("film");
    t_model->setHeaderData(0, Qt::Horizontal, tr("Title"));
    t_model->setHeaderData(1, Qt::Horizontal, tr("Description"));

   QString req;
    switch(typeRequest){
    case 1:
        t_model->setQuery("SELECT title, description FROM film", dataBase->getDB());
        t_model->submit();
        view->setModel(t_model);
        view->setColumnWidth(0,300);
        view->setColumnWidth(1, 300);
        if (t_model->lastError().isValid()){
            qDebug() << t_model->lastError();
        }
        break;
    case 2:
        req = "SELECT title, description FROM film f JOIN film_category "
                       "fc on f.film_id = fc.film_id JOIN category c on c.category_id = fc.category_id WHERE c.name = 'Comedy';";
        q_model->setQuery(req, dataBase->getDB());
        view->setModel(q_model);
        view->setColumnWidth(0,300);
        view->setColumnWidth(1, 300);
        if (q_model->lastError().isValid()){
            qDebug() << q_model->lastError();
        }
        break;
    case 3:
        req = "SELECT title, description FROM film f JOIN film_category "
              "fc on f.film_id = fc.film_id JOIN category c on c.category_id = fc.category_id WHERE c.name = 'Horror';";
        q_model->setQuery(req, dataBase->getDB());
        view->setModel(q_model);
        view->setColumnWidth(0,300);
        view->setColumnWidth(1, 300);
        if (q_model->lastError().isValid()){
            qDebug() << q_model->lastError();
        }
        break;
    }

    view->show();
}
/*!
 * \brief Метод изменяет стотояние формы в зависимости от статуса подключения к БД
 * \param status
 */
void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status){
        ui->act_connect->setText("Отключиться");
        ui->lb_statusConnect->setText("Подключено к БД");
        ui->lb_statusConnect->setStyleSheet("color:green");
        ui->pb_request->setEnabled(true);
    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        msg->exec();
    }

}




void MainWindow::on_pb_clear_clicked()
{
    ui->tb_result->clear();
    view->close();
}

