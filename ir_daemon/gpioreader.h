/**
 * EasyRaceLapTimer - Copyright 2015-2016 by airbirds.de, a project of polyvision UG (haftungsbeschränkt)
 *
 * Author: Alexander B. Bierbrauer
 *
 * This file is part of EasyRaceLapTimer.
 *
 * OpenRaceLapTimer is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * OpenRaceLapTimer is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with Foobar. If not, see http://www.gnu.org/licenses/.
 **/
#ifndef GPIOREADER_H
#define GPIOREADER_H

#include <QObject>
#include "singleton.h"
#include <QHash>

class GPIOReader: public QObject, public Singleton<GPIOReader>
{
    friend class Singleton<GPIOReader>;
    Q_OBJECT
    
public:
    GPIOReader();
    void setDebug(bool);
    void update();
    unsigned int num_ones_in_buffer(QList<int>& list);
    void print_binary_list(QList<int>& list);
    void push_to_service(int sensor_i,QList<int>& list,int control_bit);
    void push_bit_to_sensor_data(unsigned int pulse_width,int sensor_i);
    void reset();
signals:
    void    newLapTimeEvent(QString,unsigned int);

public slots:
private:
    bool m_bDebugMode;
    int sensor_state[3];
    int sensor_pins[3];
    unsigned int sensor_pulse[3];
    unsigned int sensor_start_lap_time[3];
    QHash<QString, unsigned int> m_sensoredTimes;
    QList<int> sensor_data[3];
};

#endif // GPIOREADER_H
