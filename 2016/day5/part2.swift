import Foundation
import CommonCrypto

// begin code taken from https://stackoverflow.com/questions/32163848/how-can-i-convert-a-string-to-an-md5-hash-in-ios-using-swift

func MD5(_ string: String) -> String? {
    let length = Int(CC_MD5_DIGEST_LENGTH)
    var digest = [UInt8](repeating: 0, count: length)
    
    if let d = string.data(using: String.Encoding.utf8) {
        _ = d.withUnsafeBytes { (body: UnsafePointer<UInt8>) in
            CC_MD5(body, CC_LONG(d.count), &digest)
        }
    }
    
    return (0..<length).reduce("") {
        $0 + String(format: "%02x", digest[$1])
    }
}

// end code taken from stackoverflow

func part2(_ input: String) -> String {
    var ret = Array<Character>(repeating: "G", count: 8)
    var counter = 0, charsInPassword = 0
    while charsInPassword < 8 {
        let testString: String = "\(input)\(counter)"
        if let md5String = MD5(testString) {
            let fifthIndex = md5String.index(md5String.startIndex, offsetBy: 4)
            if md5String[md5String.startIndex...fifthIndex] == "00000" {
                let sixthIndex = md5String.index(md5String.startIndex, offsetBy: 5)
                if let charAtSixth = Int(String(md5String[sixthIndex])), charAtSixth < 8 {
                    if ret[charAtSixth] == "G" {
                        let seventhIndex = md5String.index(md5String.startIndex, offsetBy: 6)
                        ret[charAtSixth] = md5String[seventhIndex]
                        charsInPassword += 1
                    }
                }
            }
        }
        counter += 1
    }
    return ret.reduce("") { (acc: String, ch: Character) -> String in
        return acc + String(ch)
    }
}

