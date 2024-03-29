#include "../../include/threading/semaphore.h"
#include "../../include/threading/thread.h"

__BEGIN_API

Semaphore::~Semaphore() {
    wakeup_all();
}

void Semaphore::p() {
    db<Semaphore>(TRC) << "Semaphore antes de p(): " << _value << "\n";
    if (CPU::fdec(_value) < 1) { 
        sleep();  // bloqueia thread
    }
}

void Semaphore::v() {
     db<Semaphore>(TRC) << "Semaphore antes de v(): " << _value << "\n";
    if (CPU::finc(_value) < 0) {
        wakeup();
    }
}

void Semaphore::sleep() {
    Thread* thread_running = Thread::running();
    thread_running->sleep(&_sleeping); 
    db<Semaphore>(TRC) << " - Semáforo fazendo sleep em Thread " << thread_running->id() << "\n";
}

void Semaphore::wakeup() {
    Thread* thread_waking_up = _sleeping.remove_head()->object();
    db<Semaphore>(TRC) << " - Semáforo fazendo wakeup em Thread " << thread_waking_up->id() << "\n";
    thread_waking_up->wakeup();
}

void Semaphore::wakeup_all() {
    db<Semaphore>(TRC) << " - Semáforo fazendo wakeup_all\n";
    while (!_sleeping.empty()) {
        wakeup();
    }
}

__END_API
