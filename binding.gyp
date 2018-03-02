{
  "targets": [
    {
      "target_name": "chacha8",
      "sources": [
        "src/chacha8native.cc",
        "src/chacha8_simple.cc",
        "src/chacha.cc",
        # "src/poly.cc",
        # "src/poly1305-donna.cc",
        # "src/aead.cc",
        # "src/legacy.cc"
        ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
