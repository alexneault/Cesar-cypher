test_folder=tests
prog=cesar

#Tout les tests

@test "Majuscule et minuscule" {
    run ./$prog $test_folder/entree1.txt $test_folder/sortie1.txt
    run cat $test_folder/sortie1.txt
    [ "$status" -eq 0 ] 
    [ "${lines[0]}" = "Cours Automne" ]
    [ "${lines[1]}" = "Serge Dogny" ]
    [ "${lines[2]}" = "Ce programme permet de dechiffrer une" ]
    [ "${lines[3]}" = "ENCRYPTION DE CESAR" ]
}

@test "aucun argument" {
    run ./$prog
    [ "$status" -eq 1 ]
    [ "${lines[0]}" = "Décryption de César" ]
    [ "${lines[1]}" = "./cesar [Fichier Entree] [Fichier Sortie]" ]
}

@test "Message avec chiffres" {
    run ./$prog $test_folder/entree2.txt $test_folder/sortie2.txt
    run cat $test_folder/sortie2.txt
    [ "$status" -eq 0 ]
    [ "${lines[0]}" = "Cours Automne 2021" ]
    [ "${lines[1]}" = "INF3135" ]
}

@test "Trop d'argument" {
    run ./$prog $test_folder/entree2.txt $test_folder/sortie2.txt $test_folder/sortie2.txt
    [ "$status" -eq 1 ]
    [ "${lines[0]}" = "Il doit y avoir exactement deux arguments" ]
}

@test "Fichier d'entree invalide" {
    run ./$prog $test_folder/asdassfjk $test_folder/sortie4.txt
    [ "$status" -eq 1 ]
    [[ "${lines[0]}" = *": No such file or directory" ]]
}


