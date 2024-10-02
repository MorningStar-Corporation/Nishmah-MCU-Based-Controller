// --------------------------------------------------------------------------------------------------
//  File        : main.c
//  Description : Main Source File for the Controller
//  Author      : Stein
//
//  Creation Date     : 2024-10-02T03:13:37-03:00
//  Modification Date : 2024-10-02T03:13:37-03:00
//  Version           : 0.0.0
//
//  Notes: None
//
//  Copyright(C) 2024 MorningStar Corporation International. All Rights Reserved.
// --------------------------------------------------------------------------------------------------

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main()
{
    stdio_init_all();

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // Enable wifi station
    cyw43_arch_enable_sta_mode();

    printf("Connecting to Wi-Fi...\n");
    if (cyw43_arch_wifi_connect_timeout_ms("Your Wi-Fi SSID", "Your Wi-Fi Password", CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("failed to connect.\n");
        return 1;
    } else {
        printf("Connected.\n");
        // Read the ip address in a human readable way
        uint8_t *ip_address = (uint8_t*)&(cyw43_state.netif[0].ip_addr.addr);
        printf("IP address %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
    }

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
