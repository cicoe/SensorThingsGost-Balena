package main

import (
	"fmt"
    "time"

//	"log"
//	"net/http"
)

func main() {
/*	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		w.Write([]byte("hello, world (from go!)\n"))
	})
	addr := ":80"
	fmt.Println("Example app listening on port ", addr)
	log.Fatal(http.ListenAndServe(addr, nil))
*/
    for {
        fmt.Println("hello world")
        time.Sleep(10 * time.Second)
	}
}
