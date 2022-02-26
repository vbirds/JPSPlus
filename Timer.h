/*
 * $Id: timer.h,v 1.5 2006/10/30 17:45:10 nathanst Exp $
 *
 * timer.h
 * HOG file
 *
 * Written by Renee Jansen on 08/28/06
 *
 * This file is part of HOG.
 *
 * HOG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * HOG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HOG; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <cstdint>
#include <fstream>
#include <sys/time.h>

class Timer {
private:
    //unsigned int startTimeInMS;
    struct timeval start, end;

public:
    Timer();

    ~Timer() {}

    void StartTimer();

    int64_t EndTimer();

    int64_t GetElapsedTime()
    {
        return ((int64_t)end.tv_sec-(int64_t)start.tv_sec)*1000 +
               ((int64_t)end.tv_usec-(int64_t)start.tv_usec)/1000;
    }
};
