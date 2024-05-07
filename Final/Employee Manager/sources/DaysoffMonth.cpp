//
// Created by Trong_Phuc on 21/04/2024.
//
#include "../headers/DaysoffMonth.h"

void Daysoff_Month::set_available(int data) {
    available = data;
    stored_day -= data;
}

void Daysoff_Month::set_unavailable(int data) {
    unavailable = data;
    stored_day -= data;
}

int Daysoff_Month::get_available() const { return available; }

int Daysoff_Month::get_unavailable() const { return unavailable; }

int Daysoff_Month::get_storedDay() const { return stored_day; }